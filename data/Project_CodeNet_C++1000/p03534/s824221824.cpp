#include <iostream>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;
int a[110000];
const int maxn=1e5;
string code="AKIHABARA",st;
int cnt[5]={0};
int main(int argc, const char * argv[])
{
    cin>>st;
    int len=st.length();
    for(int i=0;i<len;i++)cnt[st[i]-'a']++;
    sort(cnt+0,cnt+3);
    if(cnt[2]-cnt[0]>1)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
