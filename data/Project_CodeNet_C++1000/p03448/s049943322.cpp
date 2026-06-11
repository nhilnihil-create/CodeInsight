#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
    int A,B,C,X;
    cin >> A >> B >> C>> X;
    int count =0;
    int total_price;
    for(int i=0;i<=A;i++){
        for(int j=0;j<=B;j++){
            for(int k=0;k<=C;k++){
                total_price = 500 * i + 100 * j + 50 * k;
                if(total_price == X){
                    count = count + 1;
                }
            }
        }
    }
    cout << count << endl;
}