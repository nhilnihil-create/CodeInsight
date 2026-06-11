#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> c(n-1),s(n-1),f(n-1);
    for(int i=0; i<n-1; i++){
        cin >> c.at(i) >> s.at(i) >> f.at(i);
    }
    for(int i=0; i<n; i++){
        //開始時に駅iにいる
        int time=0;
        for(int j=i; j<n-1; j++){
            //駅jから駅j+1に移動
            int train=s.at(j);
            while(train<time){
                train+=f.at(j);
            }
            time=train+c.at(j);
        }
        cout << time << endl;
    }
}