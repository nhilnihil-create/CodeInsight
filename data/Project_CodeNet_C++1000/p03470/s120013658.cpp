#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<int> A;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(),A.end());
    int dan = 1;
    for(int j=0;j<n-1;j++){
        if(A.at(j) < A.at(j+1)){
            dan++;
        }
    }
    cout << dan << '\n';
    return 0;
}
