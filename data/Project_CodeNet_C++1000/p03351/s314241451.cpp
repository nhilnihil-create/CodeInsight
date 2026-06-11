#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int abs(int x,int y){
    if(x>y) return x-y;
    else return y-x;
}

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(((abs(a,b)<=d)&&(abs(b,c)<=d))||(abs(a,c)<=d)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

}
