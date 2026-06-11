#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int A,B;
    cin >> A >> B;
    //string strA = to_string(A);
    //string strB = to_string(B);
    int count;
    string str;
    for(int i=A; i<=B; i++){
        str = to_string(i);
        if(str[0] == str[4] && str[1] == str [3]){
            count++;
        }
    }
    
    cout << count << endl;
}