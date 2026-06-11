#include<bits/stdc++.h>

using namespace std;

int main()
{
    int kind,a,b;
    while(cin >> kind){
        if(kind == 1){
            cout << "Hello World" << endl;
        } else {
            cin >> a >> b;
            cout << (a+b) << endl;
        }
    }
	return 0;
}