#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
char s[N];
int main()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    if(s[1]=='0'||s[n]=='1'){
        puts("-1");return 0;
    }
    for(int i=1;i<n;i++){
        if(s[i]!=s[n-i]){
            puts("-1");return 0;
        }
    }
    int rt=1;
    for(int i=2;i<=n;i++){
        cout<<rt<<" "<<i<<endl;
        if(s[i-1]=='1')rt=i;
    }
    return 0;
}
