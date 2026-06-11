#include<bits/stdc++.h>
#define ll long long 
#define P pair<ll ,ll>
using namespace std;

int main(){
    vector<int>vec(3);
    cin >> vec[0] >> vec[1] >> vec[2];
    sort(vec.begin() ,vec.end());

    int ans = 0;
    while(!(vec[0] == vec[1] && vec[1] == vec[2])){
        if(vec[1]!=vec[2]){
            vec[0]++;
            vec[1]++;
            ans++;
        }else{
            vec[0] += 2;
            ans++;
        }sort(vec.begin() ,vec.end());
    }
    cout << ans << endl;
}