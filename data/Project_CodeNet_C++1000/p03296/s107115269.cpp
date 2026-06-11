#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<int> vec(N);
    rep(i,N){
        cin >> vec[i];
    }
    vector<pair<int,int> > number(0);
    number.push_back(pair<int,int>(vec[0],1));
    int ans = 0;
    rep(i,N - 1){
        if (vec[i] != vec[i + 1]){
            number.push_back(pair<int,int>(vec[i + 1], 1));
        }
        else{
            number[number.size() - 1].second++;
        }
    }
    int len = number.size();
    rep(i,len){
        ans += (number[i].second / 2);
    }
    cout << ans << endl;
}

