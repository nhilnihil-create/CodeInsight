#include<iostream>
#include<algorithm>
using namespace std;

class piza{
    public:
    int num;
    int price;
};

int main(){
    piza A, B, C, more, less;
    cin >> A.price >> B.price >> C.price >> A.num >> B.num;
    if(A.num > B.num){
        more = A;
        less = B;
    }
    else{
        less = A;
        more = B;
    }

    //ABピザ割高
    if(A.price+B.price <= 2*C.price) cout << A.price*A.num + B.price*B.num << endl;

    //ABピザ割安
    else{
        //ABピザ破格
        if(more.price >= 2*C.price){
            cout << 2*C.price*more.num << endl;;
        }
        //ABピザ普通
        if(more.price < 2*C.price){
            cout << 2*less.num * C.price + (more.num-less.num) * more.price << endl;
        }
    }
}