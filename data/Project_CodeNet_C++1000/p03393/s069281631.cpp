#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
using namespace std;
inline int read(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 26+5;
int n, vis[N]; char s[N];
int main()
{
    scanf("%s", s+1), n = strlen(s+1);
    if(n < 26)
    {
        int c = 0;
        for(int i = 1; i <= n; ++i) 
        {
            vis[s[i]-'a'] = 1;
            while(vis[c]) ++c;
        }
        s[n+1] = c+'a';
        return puts(s+1), 0;
    }
    else
    {
        for(int i = n-1; i; --i)
        {
            int k = i;
            for(int j = i+1; j <= n; ++j) if(s[j]>s[i]&&(s[k]>s[j]||k == i)) k = j;
            if(k == i) continue; s[i] = s[k], s[i+1] = 0; 
            return puts(s+1), 0;
        }
    }
    puts("-1");
    return 0;
}