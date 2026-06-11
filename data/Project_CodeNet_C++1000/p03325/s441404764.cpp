#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a.at(i);
    }

    long int count=0;
    for(int i=0; i<n; i++){
        while(1){
            if(a.at(i)%2) break;
            else{
                count++;
                a.at(i)/=2;
            }
        }
    }
    cout << count << endl;
}