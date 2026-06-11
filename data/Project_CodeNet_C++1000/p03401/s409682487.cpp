#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> A(n+2);
    A.at(0)=0;
    A.at(n+1)=0;
    int total=0;
    for(int i=1; i<=n; i++){
        int a;
        cin >> a;
        A.at(i) = a;
        total += abs(A.at(i) - A.at(i-1));
    }
    total+=abs(A.at(n));

    for(int i=1; i<n+1; i++){
        cout << total - (abs(A.at(i)-A.at(i-1))+ abs(A.at(i)-A.at(i+1)))
                    + abs(A.at(i+1)-A.at(i-1)) << endl;
    }
}