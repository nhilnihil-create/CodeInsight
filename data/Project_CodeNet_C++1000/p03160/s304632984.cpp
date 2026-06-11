#include<bits/stdc++.h>
using namespace std;

int main(){
    int N=0;
    cin >> N;
    vector<int>dp(N);
    vector<int>a(N);
    for (int i=0; i<N; i++){
        cin >> a.at(i);
    }
    dp.at(0)=0;

    for(int i=1;i<N;i++){
        if(i-2>=0){
            dp.at(i) = min(dp.at(i-2) + abs(a.at(i)-a.at(i-2)), dp.at(i-1) + abs(a.at(i)-a.at(i-1)));
        }else{
            dp.at(i) = dp.at(i-1) + abs(a.at(i-1) - a.at(i));
        }
    }
    cout << dp.at(N-1) << endl;
} 