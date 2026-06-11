#include <bits/stdc++.h> 
using namespace std;

#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define pb					push_back
#define eb					emplace_back
#define mp					make_pair
#define endl 				'\n'
#define gc					getchar_unlocked
#define pc					putchar_unlocked
#define FASTIO std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define N 1000000
#define MAX_DIGITS 7 // 7 digits in 1 000 000
static const long long buf_len = (1 << 14);
static const long long buf_max = (1 << 04);
static char buf_out[buf_len];
static char buf_num[buf_max];
static long long buf_pos = 0;
#ifdef _WIN32
#define GETCHAR() _getchar_nolock()
#define PUTCHAR(c) _putchar_nolock(c)
#elif __unix__
#define GETCHAR() getchar_unlocked()
#define PUTCHAR(c) putchar_unlocked(c)
#else
#define GETCHAR() getchar()
#define PUTCHAR(c) putchar(c)
#endif
#define MOD 1000000007  
#define lld long long 
static const lld nax=1e5+5;
short ch = 0;

 inline string ipst()
{
    string i="";
    long long temp=getchar_unlocked();
    while(temp<'a'||temp>'z')
        temp=getchar_unlocked();
    while(temp>='a'&&temp<='z')
    {
        i+=(char)temp;
        temp=getchar_unlocked();
    }
    return i;
}

 inline int getLine(string &str) {
        str = "";
        if (ch == -1) return -1;
        while (ch < 33 || ch == 127) {ch = getchar_unlocked(); if (ch == -1) return -1;}
        while (ch > 31 && ch < 127) {
            str.push_back(ch);
            ch = getchar_unlocked();
        }
        return str.size();
 }

inline void opst(string &str) {
        long long len = str.length();
        for (int i=0; i<len; i++) putchar_unlocked(str[i]);
}

 inline lld cinll(){
	char r;
	bool start=false,neg=false;
	lld ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}
 
 inline void coutll(long long n)
{
    if(n == 0)
    {
        PUTCHAR('0');
        return;
    }
 
    if(n < 0)
    {
        PUTCHAR('-');
        n = -n;
    }
 
    char buffer[MAX_DIGITS];
    long long i = MAX_DIGITS - 1;
 
    while(n)
    {
        buffer[i--] = n % 10 + '0';
        n /= 10;
    }
 
    while(i != MAX_DIGITS - 1) 
    {
        PUTCHAR(buffer[++i]);
    }
}

double kq[305][305][305];
double p[305][305][305];

int main() {
    FASTIO
    int n;
    vector<lld>cnt(4);
    cin>>n;
    for(int i=0;i<n;i++)
    	{
    		int x;
    		cin>>x;
    		cnt[x]++;
    	}
    
    p[cnt[1]][cnt[2]][cnt[3]]=1;
    
    //p[one][two][three]=1;
    for(int c=n;c>=0;c--)
    {
    	for(int b=n;b>=0;b--)
    	{
    		for(int a=n;a>=0;a--)
    		{
    			if(a==0&&b==0&&c==0)
    			{
    				continue;
    			}
    			if(a+b+c>n)
    			{
    				continue;
    			}
    			double p_waste=(double)(n-(a+b+c))/n;
    			double kq_waste=p_waste/(1-p_waste)+1;
    			kq[a][b][c]+=kq_waste*p[a][b][c];
    			if(a!=0)
    			{
    				double p_go=(double)a/(a+b+c);
    				p[a-1][b][c]+=p[a][b][c]*p_go;
    				kq[a-1][b][c]+=kq[a][b][c]*p_go;
    			}
    			if(b!=0)
    			{
    				double p_go=(double)b/(a+b+c);
    				p[a+1][b-1][c]+=p[a][b][c]*p_go;
    				kq[a+1][b-1][c]+=kq[a][b][c]*p_go;
    			}
    			if(c!=0)
    			{
    				double p_go=(double)c/(a+b+c);
    				p[a][b+1][c-1]+=p[a][b][c]*p_go;
    				kq[a][b+1][c-1]+=kq[a][b][c]*p_go;
    			}
    		}
    	}
    }
	printf("%.9lf\n",kq[0][0][0]);
}