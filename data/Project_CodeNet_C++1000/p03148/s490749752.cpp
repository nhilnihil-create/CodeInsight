#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>

#define ll long long

using namespace std;

long long MOD = 1000000007;

template<typename T>
void cout_vec(vector<T> &vec){
    for(int i=0; i<vec.size(); i++){
        if (i!=0){
            cout << ' ';
        }
        cout << vec[i];
    }
    cout << endl;
}

int main(){
    int N, K;
    cin >> N >> K;

    vector<ll> t_vec(N+1,-MOD*MOD);
    vector<ll> rest(0);

    for(int i=0; i<N; i++){
        ll t, d;
        cin >> t >> d;
        t--;
        if(t_vec[t]<d){
            rest.push_back(t_vec[t]);
            t_vec[t]=d;
        }else{
            rest.push_back(d);
        }
    }
    sort(t_vec.rbegin(), t_vec.rend());
    sort(rest.rbegin(), rest.rend());

    for(int i=0; i<N; i++){
        t_vec[i]+=(ll) 2*i+1;
    }

    //cout_vec(t_vec);

    ll ans = 0;
    int j=0;int k=0;    
    for(int i=0; i<K; i++){
        if(t_vec[j]>=rest[k]){
            ans+=t_vec[j];
            j++;
        }else{
            ans+=rest[k];
            k++;
        }
    }

    ll tmp=0;
    j=0;
    for(int i=0; i<K; i++){
        if(t_vec[i]>0){
            tmp+=t_vec[i];
        }else{
            tmp+=rest[j];
            j++;
        }
    }

    cout << max(tmp, ans) << endl;
}