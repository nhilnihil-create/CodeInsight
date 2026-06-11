#include<iostream>
#include<climits>

using namespace std;
// Problem https://atcoder.jp/contests/arc096/tasks/arc096_a
int solver(int pizzaAPr,int pizzaBPr,int pizzaABHPr,int needA,int needB){
    int result = INT_MAX ;
    // cout << pizzaAPr << " " << pizzaBPr << " " << pizzaABHPr << " " << needA << " " << needB << endl;
    for(int j=0;j<=200000;j=j+2){
        int pizzaAPrPiece = j / 2;
        int pizzaBPrPiece = j / 2;
        int moreNeedA = max(0,needA-pizzaAPrPiece);
        int moreNeedB = max(0,needB-pizzaBPrPiece);
        int sumMoney=j*pizzaABHPr + pizzaAPr * moreNeedA + pizzaBPr * moreNeedB;
        if(sumMoney < result){
            result = sumMoney;
        }
    }

    return result;
}

int main(void){
    int A,B,C,X,Y;
    int answer=0;
    cin >> A >> B >> C >> X >> Y;
    answer=solver(A,B,C,X,Y);
    cout << answer << endl;
    return 0;
}