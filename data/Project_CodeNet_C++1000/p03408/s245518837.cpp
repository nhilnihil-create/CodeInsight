#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M,blue_point,red_point,best_sum=-110;
    cin >> N;
    vector<string>blue(N);
    for(int i=0;i<N;i++)cin >> blue.at(i);
    cin >> M;
    vector<string>red(M);
    for(int i=0;i<M;i++)cin >> red.at(i);

    for(int i=0;i<N;i++){
        blue_point=count(blue.begin(),blue.end(),blue.at(i));
        red_point=count(red.begin(),red.end(),blue.at(i));
        best_sum=max(blue_point-red_point,best_sum);
    }

    if(best_sum>=0){
        cout << best_sum;
    } else {
        cout << 0;
    }
    return 0;
}