#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const long long mod = 1000000007;
const long long inf = 1e18;

bool sieve[100001]; // 1 = composite 0=prime

void sievealgo(void){
    sieve[1]=1;
    sieve[0]=1;
    for(int i=4;i<=100000;i+=2){
        sieve[i]=1;
    }
    for(int i=3;i<=100000;i+=2){
        if(sieve[i]==0){
            for(int j=2*i;j<=100000;j+=i){
                sieve[j]=1;
            }
        }
    }
}



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int arr[100001];
    arr[0]=0;
    sievealgo();
    for(int i=1;i<=100000;i++){
        arr[i]=arr[i-1];
        if((i&1)==0){
            continue;
        }
        else{
            if(sieve[i]==0 && sieve[(i+1)/2]==0){
                arr[i]+=1;
            }
        }
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        cout<<arr[r]-arr[l-1]<<endl;
    }
    return 0;
}
