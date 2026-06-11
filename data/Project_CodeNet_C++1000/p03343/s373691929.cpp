    #include <cstdio>
    #include <set>
    #include <iostream>
    #include <cmath>
    #include <cstdlib>
    #include <algorithm>
    #include <cstring>
    #include <queue>
    #include <map>
    #include<numeric>
    #include <list>
    #define fo(a, b, c) for (register int a = b; a <= c; ++a)
     
    namespace IO
    {
        inline char gc()
        {
            static char s[1<<20|1]={0},*p1=s,*p2=s;
            return (p1==p2)&&(p2=(p1=s)+fread(s,1,1<<20,stdin),p1==p2)?EOF:*(p1++);
        }
    //	inline char gc() { return getchar(); }
    	inline long long read()
    	{
    		long long ret=0;bool flag=0;char c=gc();
    		while ((c<'0')|(c>'9')) flag ^= !(c^'-'),c=gc();
    		while ((c>='0')&(c<='9')) ret=(ret<<1)+(ret<<3)+(c^'0'),c=gc();
    		return flag?-ret:ret;
     	}
     	char OutputAns[1<<20|1],*OutputCur = OutputAns;
     	inline void output()
     	{
     		OutputCur -= fwrite(OutputAns,1,OutputCur - OutputAns,stdout);
    	}
    	inline void print(long long ans)
    	{
    		char s[20]={0};
    		if (OutputCur - OutputAns + sprintf(s,"I64d",ans) >> 20) output();
    		OutputCur += sprintf(OutputCur,"%I64d",ans);
    	}
    	inline void printc(char c)
    	{
    		if (OutputCur - OutputAns + 1 >> 20) output();
    		*(OutputCur++) = c;
    	}
    }
     
    using IO::read;
    using IO::print;
    using IO::printc;
    using IO::output;
     
    using namespace std;
     
    typedef long long int64;
     
    const int M = 2e3 + 11;
     
    int lim, n, q, ans = 2e9;
     
    int A[M], Rev[M];
     
    class SegmentTree
    {
    	public:
    		int Max[M<<2], Min[M<<2];
    	private:
    		inline void P1(int k) { Min[k] = std::min(Min[k<<1], Min[k<<1|1]); }
    		inline void P2(int k) { Max[k] = std::max(Max[k<<1], Max[k<<1|1]); }
    	public:
    		inline void Clr() { memset(Min, 127, sizeof Min); }
    		inline void UpD(int k, int l, int r, int pos)
    		{
    			if (l == r) { Max[k] = Min[k] = l; return ; }
    			int mid = l + r >> 1;
    			if (pos <= mid) UpD(k<<1, l, mid, pos);
    			else UpD(k<<1|1, mid + 1, r, pos); P1(k), P2(k);
    		}
    		inline int QMax(int k, int l, int r, int x, int y)
    		{
    			if (x > y) return 0;
    			if (x <= l && y >= r) return Max[k];
    			int mid = l + r >> 1, res = 0;
    			if (x <= mid) res = QMax(k<<1, l, mid, x , y);
    			if (y > mid) res = std::max(res, QMax(k<<1|1, mid + 1, r, x, y));
    			return res;
    		}
    		inline int QMin(int k, int l, int r, int x, int y)
    		{
    			if (x > y) return n + 1;
    			if (x <= l && y >= r) return Min[k];
    			int mid = l + r >> 1, res = n + 1;
    			if (x <= mid) res = QMin(k<<1, l, mid, x , y);
    			if (y > mid) res = std::min(res, QMin(k<<1|1, mid + 1, r, x, y));
    			return res;
    		}
    } T;
     
    class Tree
    {
    	public:
    		int o[M];
    		inline void Clr() { memset(o, 0, sizeof o); }
    		inline void Add(int p, int v) { while (p <= n) o[p] += v, p += p & -p; }
    		inline int Sum(int p) { int v = 0; while (p) v += o[p], p -= p & -p; return v; }
    } S;
     
    inline bool cmp(const int& x, const int& y) { return A[x] < A[y]; }
     
    inline void Input()
    {
    	n = read(), lim = read(), q = read();
    	for (int i = 1;i <= n; ++i)
    		A[i] = read(), Rev[i] = i;
    	std::sort(Rev + 1, Rev + 1 + n, cmp);
    }
     
    inline void Solve()
    {
    	T.Clr();
    	for (int i = 1;i <= n; ++i)
    	{
    		int pos = Rev[i], now = i; S.Clr();
    		int _max = 0, _min = 2e9;
    		for (int j = 1;j <= q; ++j)
    		{
    		//	printf("%d\n", Rev[now] - 1);
    			int l, r;
    			//printf("%d %d\n", l, r);
    			while (now <= n && (r = T.QMin(1, 1, n, Rev[now] + 1, n), 
    			l = T.QMax(1, 1, n, 1, Rev[now] - 1), r - l - (S.Sum(r - 1) - S.Sum(l)) <= lim)) ++now;
    			if (now > n) goto end;
    			_min = std::min(_min, A[Rev[now]]), _max = std::max(_max, A[Rev[now]]);
    			S.Add(Rev[now], 1); now++;
    		}
    		ans = std::min(ans, _max - _min);
    		end:; T.UpD(1, 1, n, pos);
    	} printf("%d\n", ans);
    }
     
    int main(void)
    {
    	Input();
    	Solve();
    }