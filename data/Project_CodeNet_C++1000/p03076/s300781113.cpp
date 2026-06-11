#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> time(5);
    vector<int> wait(5);
    int maxwait=0;
    int sum=0;
    for(int i=0; i<5; i++){
        cin >> time.at(i);
        wait.at(i)=time.at(i)%10;
        if(wait.at(i)) wait.at(i)=10-wait.at(i);
        maxwait=max(maxwait,wait.at(i));
        sum+=time.at(i)+wait.at(i);
    }
    cout << sum-maxwait << endl;
}