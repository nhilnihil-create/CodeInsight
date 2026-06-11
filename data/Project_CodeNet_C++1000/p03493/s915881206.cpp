#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;
int main()
{
    int c=0;
    string a;
    getline(cin,a);
    if(a[0]=='1'){
        c++;
    }
    if(a[1]=='1'){
        c++;
    }
    if(a[2]=='1'){
        c++;
    }
    cout << c;
	
}
