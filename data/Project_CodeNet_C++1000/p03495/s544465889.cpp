#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,k;
    cin >> n >> k;
    map<int,int> ball;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        ball[a]++;
    }
    vector<int> num;
    for(auto p:ball){
        num.push_back(p.second);
    }
    sort(num.begin(), num.end());
    reverse(num.begin(), num.end());
    int ans=0;
    for(int i=0; i<num.size(); i++){
        if(i<k) continue;
        ans += num.at(i);
    }
    cout << ans << endl;
}