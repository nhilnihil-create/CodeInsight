#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; cin>>n;
    map<int, int> even;
    map<int, int> odd;
    for (int i=0; i<n; i++){
        int v; cin>>v;
        if(i%2==0){
            if(even.count(v)){
                even[v]=even[v]+1;
            }
            else even[v]=1;
        }
        if(i%2!=0){
            if(odd.count(v)){
                odd[v]=odd[v]+1;
            }
            else odd[v]=1;
        }
    }
    auto even_begin = even.begin(), even_end = even.end();
    auto odd_begin = odd.begin(), odd_end = odd.end();
    ll even1 = 0, even2=0, even1_idx=-1, even2_idx=-1;
    ll odd1 = 0, odd2=0, odd1_idx=-1, odd2_idx=-1;

    for(auto iter = even_begin; iter != even_end; iter++){
        int key = iter->first, value = iter->second;
        if(value>even1){
            even2=even1; even2_idx=even1_idx; even1=value, even1_idx=key;
        }
        else if(value>even2){
            even2 = value; even2_idx=key;
        }
        //cout << key << " " << value << endl;
    }

    for(auto iter = odd_begin; iter != odd_end; iter++){
        int key = iter->first, value = iter->second;
        if(value>odd1){
            odd2=odd1; odd2_idx=odd1_idx; odd1=value, odd1_idx=key;
        }
        else if(value>odd2){
            odd2 = value; odd2_idx=key;
        }
        //cout << key << " " << value << endl;
    }

    ll ans = n;
    if(even1_idx != odd1_idx) ans -= (even1+odd1);
    else ans -= max(even1+odd2, even2+odd1);


    cout << ans << endl;
}