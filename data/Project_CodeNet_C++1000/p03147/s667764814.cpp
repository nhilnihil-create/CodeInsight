#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> h(n);
    int highest=0;
    for(int i=0; i<n; i++){
        cin >> h.at(i);
        highest=max(highest,h.at(i));
    }

    int count=0;
    bool grow=false;
    for(int i=0; i<highest; i++){
        for(int j=0; j<n; j++){
            if(h.at(j)>i) grow=true;
            if(grow){
                if(h.at(j)<=i || j==n-1){
                    count++;
                    grow=false;
                }
            }
        }
    }

    cout <<count << endl;
}