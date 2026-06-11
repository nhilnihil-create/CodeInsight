#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int a,b,c,d;
cin >> a;
cin >> b;
cin >> c;
cin >>d;

if((a+b) > (c+d)){
cout << "Left" << endl;
}
else if((a+b) == (c+d)){
cout << "Balanced" <<endl;
}
else{
cout << "Right" <<endl;
}

}