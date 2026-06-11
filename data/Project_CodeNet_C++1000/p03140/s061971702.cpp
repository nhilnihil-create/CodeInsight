#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int MOD=1000000007;
const int nmax=2512;

int n,cnt;
char a[112],b[112],c[112];

int main()
{
    scanf("%d",&n);
    scanf("%s",a);
    scanf("%s",b);
    scanf("%s",c);
    for(int i=0;i<n;++i){
        if(a[i]==b[i] && a[i]==c[i]){

        }
        else if(a[i]==b[i] || b[i]==c[i] || a[i]==c[i]){
            ++cnt;
        }
        else{
            cnt+=2;
        }
    }
    printf("%d",cnt);
    return 0;
}
