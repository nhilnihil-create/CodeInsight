#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> N;
    for(int i=0; i<3; i++){
        int n; cin >> n;
        N.push_back(n); 
    }

    sort(N.begin(),N.end());
    int a = N.at(0);
    int b = N.at(1);
    int c = N.at(2);
    int ans;

    if(a%2 == b%2){
        ans = (b-a)/2 + c-b;
    }else{
        ans = c-b + (b-a+1)/2 + 1;
    }
    cout << ans << endl;
}