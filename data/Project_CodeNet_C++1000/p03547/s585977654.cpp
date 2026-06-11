#include <bits/stdc++.h>
using namespace std;

int conv(char c){
    if(c == 'A') return 10;
    else if(c == 'B') return 11;
    else if(c == 'C') return 12;
    else if(c == 'D') return 13;
    else if(c == 'E') return 14;
    else return 15;
}

int main(){
    char x, y;
    cin >> x >> y;
    int xn = conv(x);
    int yn = conv(y);

    if(xn > yn) cout << ">" << endl;
    else if(xn == yn) cout << "=" << endl;
    else cout << "<" << endl;

}