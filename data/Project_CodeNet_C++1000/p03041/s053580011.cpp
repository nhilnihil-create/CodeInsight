#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int a, b;
    cin >> a >> b;
    char ch[a], c;
    for(int i=1; i<=a; i++){
        cin >> ch[i];
        if(i==b){
            c = tolower(ch[i]);
            cout << c;
        }    
        else cout << ch[i];
    }
    cout << endl;
    
    
    
    
    
    
	return 0;
}