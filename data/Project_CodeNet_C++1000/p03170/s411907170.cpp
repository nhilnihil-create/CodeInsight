// link here :
#include <bits/stdc++.h>
using namespace std;

#define NAME "rewind"
#define show(x) cout << (#x) << " is " << (x) << endl
#define ll long long
#define ms(arr,val) memset(arr,val,sizeof(arr))
#define len length()

const int maxn = 1e5;
bool first[maxn+1];
int a[100];
int main(){
    //ifstream cin(NAME".inp");
    //ofstream cout(NAME".out");
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<=k;i++){
        for(int j = 0;j<n && i - a[j] >=0 ;j++)
            if(!first[ i - a[j] ]) {
                    first[i] = true;
                    break;
            }
    }
    if (first[k])
        cout<<"First"<<endl;
    else
        cout<<"Second"<<endl;
}
