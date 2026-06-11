#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> D(101); // 0でラベル化
    for(int i=0;i<N;i++){
        int d;
        cin >> d ;
        D.at(d) = 1;   // これで同じdが来てもダブルカウント防止
    }
    int count =0;
    for(int i=0;i<101;i++){
        if(D.at(i) != 0){
            count++ ;
        }
    }
    cout << count << endl;
}