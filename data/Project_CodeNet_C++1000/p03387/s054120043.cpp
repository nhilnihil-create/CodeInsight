#include <bits/stdc++.h>
using namespace std;

int main(){
    
    vector<int> num(3);
    for(int i=0; i<3; i++){
        cin >> num.at(i);
    }

    sort(num.begin(),num.end());
    int ans=0;

    if((num.at(2)-num.at(0))%2 && (num.at(2)-num.at(1))%2){
        ans+=num.at(2)-num.at(1)+(num.at(1)-num.at(0))/2;
    }
    else if((num.at(2)-num.at(0))%2==0 && (num.at(2)-num.at(1))%2==0){
        ans+=(2*num.at(2)-num.at(1)-num.at(0))/2;
    }
    else{
        num.at(1)++;
        num.at(2)++;
        ans++;
        if((num.at(2)-num.at(0))%2 && (num.at(2)-num.at(1))%2){
        ans+=num.at(2)-num.at(1)+(num.at(1)-num.at(0))/2;
        }
        else if((num.at(2)-num.at(0))%2==0 && (num.at(2)-num.at(1))%2==0){
            ans+=(2*num.at(2)-num.at(1)-num.at(0))/2;
        }
    }

    cout << ans << endl;
}