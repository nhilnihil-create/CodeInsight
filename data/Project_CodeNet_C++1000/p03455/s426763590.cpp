#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    
    string result = "Odd";
    
    int buf = a * b;
    if(buf % 2 == 0)
    {
        result = "Even";
    }
    
    cout << result << endl;
}
