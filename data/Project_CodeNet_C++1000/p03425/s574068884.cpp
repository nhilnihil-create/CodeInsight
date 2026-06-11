#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long m=0, a=0, r=0, c=0, h=0;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        char ch = str[0];
        if(ch == 'M') m++;
        if(ch == 'A') a++;
        if(ch == 'R') r++;
        if(ch == 'C') c++;
        if(ch == 'H') h++;
    }
    long long sum = 0;
    sum += m*a*r;
    sum += m*a*c;
    sum += m*a*h;
    sum += m*r*c;
    sum += m*r*h;
    sum += m*c*h;
    sum += a*r*c;
    sum += a*r*h;
    sum += a*c*h;
    sum += r*c*h;
    cout << sum << endl;
    return 0;
}