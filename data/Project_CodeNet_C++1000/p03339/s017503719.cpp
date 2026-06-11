#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n; cin >> n;
    vector<char> vec(n);
    for(int i=0;i<n;i++) cin >> vec.at(i);

    //下処理
    vector<int> w(n);
    for(int i=1;i<n;i++){
        w.at(i) = w.at(i-1);
        if(vec.at(i-1)=='W') w.at(i)++;
    }
    vector<int> e(n);
    for(int i=n-2;i>=0;i--){
        e.at(i) = e.at(i+1);
        if(vec.at(i+1)=='E') e.at(i)++;
    }
    vector<int> person(n);
    for(int i=0;i<n;i++){
        person.at(i) = w.at(i) + e.at(i);
        //cout << w.at(i) << e.at(i) << person.at(i) << endl;
    }

    int minnum = n;
    for(int reader=0;reader<n;reader++){
        minnum = min(minnum,person.at(reader));
    }
    cout << minnum << endl;
    return 0;
}