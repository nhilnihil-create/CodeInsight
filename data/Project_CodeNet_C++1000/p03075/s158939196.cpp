#include <iostream>
#include <algorithm>
using namespace std;

int main(){
double a , b , c ,d , e , k;
cin >> a >> b >> c >> d >> e >> k;
bool t = (e-a > k);
if (t == true){
    cout << ":(" << endl;
}else{
    cout << "Yay!" << endl;
}
}