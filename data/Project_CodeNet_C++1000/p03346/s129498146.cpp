#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#include<queue>
#define N (998244353)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,P> Q;

int p[200010];



int main(void){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        p[a[i]]=i;
    }
    int len = 0;
    for(int i=1;i<=n;){
        int tmp=1;
        while(true){
            if(i==n){
                i++;
                break;
            }
            if(p[i]<p[i+1])i++,tmp++;
            else{
                i++;
                break;
            }
        }
        len = max(len,tmp);
    }
    cout<<n-len<<endl;
    return 0;
}