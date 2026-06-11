#include <iostream>
using namespace std;

int main(){

int n,t,ci,ti,menor=1001;
cin >> n >> t;

while (n>0){

cin >> ci >>ti;
n--;
if (ti<=t){
    if (ci<menor){menor=ci;}
    }
}
if (menor>1000){cout << "TLE" << endl;}
else {cout<< menor << endl;}


return 0;
}
