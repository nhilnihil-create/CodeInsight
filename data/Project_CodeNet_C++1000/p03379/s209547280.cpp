#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i=0; i<n; i++){
        cin >> a.at(i);
        b.at(i)=a.at(i);
    }
    sort(b.begin(),b.end());
    
    int num1,num2;
    num1=b.at(n/2-1);
    num2=b.at(n/2);

    for(int i=0; i<n; i++){
        if(a.at(i)<=num1) cout << num2 << endl;
        else cout << num1 << endl;
    }

}