#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
 
namespace IO{
    const int insiz = 1 << 12, outsiz = 1 << 18;
    char in[insiz], *A(in), *B(in); char out[outsiz], *ptr(out);
    inline char getc(){
    	#ifndef LOCAL
        return (A == B) && (B = (A = in) + fread(in, 1, insiz, stdin), A == B) ? EOF : *A++;
        #endif
        return getchar();
    }
    template <typename T> inline T read(){
        T ret(0), p(1); char ch(getc());
        while(ch < '0' || ch > '9'){
            if(ch == '-') p = -1; ch = getc();
        }
        while(ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getc();
        return ret*p;
    }
    inline void flush(){ fwrite(out, 1, ptr - out, stdout); ptr = out; }
    template <typename T> inline void write(T x, char cmd = '\n'){
        if(x < 0) *ptr++ = '-', x = -x;
        if(x == 0) *ptr++ = '0';
        static char s[123]; int cnt = 0;
        for(; x; x /= 10) s[++cnt] = x % 10 + '0';
        for(; cnt; --cnt) *ptr++ = s[cnt];
        *ptr++ = cmd;
        if((outsiz >> 1) > ptr - out) flush();
    }
} using IO::getc; using IO::read; using IO::write; using IO::flush;

const int maxn = 212345;
struct edge{
	int v, nxt;
}e[maxn << 1];
int fir[maxn], num(1);
inline void add(int u, int v){
	e[++num].v = v; e[num].nxt = fir[u]; fir[u] = num;
}
bool asked[maxn]; 
int main(){
	int n = read<int>();
	for(int i(1), u, v; i < n; ++i){
		u = read<int>(); v = read<int>();
		add(u, v); add(v, u);
	}
	std::queue<int> q;
	q.push(1); asked[1] = true; int las = 1;
	while(!q.empty()){
		las = q.front(); q.pop();
		for(int itr(fir[las]), v; itr; itr = e[itr].nxt){
			if(asked[v = e[itr].v]) continue;
			q.push(v); asked[v] = true;
		}
	}
	memset(asked, 0, sizeof(asked));
	int len = 0; asked[las] = true; q.push(las);
	while(!q.empty()){
		int l = q.size(); ++len;
		while(l--){
			int now = q.front(); q.pop();
			for(int itr(fir[now]), v; itr; itr = e[itr].nxt){
				if(asked[v = e[itr].v]) continue;
				q.push(v); asked[v] = true;
			}
		}
	}
	printf("%s\n", len%3 == 2 ? "Second" : "First");
	flush(); return 0;
}
