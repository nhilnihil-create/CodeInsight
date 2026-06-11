#include<bits/stdc++.h>
using namespace std;
int main(){
    string n;
    cin >> n;
    int ans1=0;
    for(int i=0; i<n.size(); i++){
        ans1 += (n[i]-'0');
    }
    int ans2= (n[0]-'0')-1;
    for(int i=0; i<n.size()-1;i++){
        ans2 += 9;
    }
    cout << max(ans1,ans2) << endl;
}


