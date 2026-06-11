#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a;
    cin >> n >> a;
    
    string result = "No";
    
    int buf = n % 500;
    if(buf <= a)
    {
        result = "Yes";
    }
    
    cout << result << endl;
}
