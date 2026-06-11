#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(void){
    int s;
    cin >> s;
    vector<int> a(1000000);
    int count=0;

    while(true){
        a[count] = s;   //配列に計算結果を入れていく
        //cout << a[count];
        if(count>0){    //今入れた値が過去にあるかどうかを確認する
            for(int i=0;i<count;i++){
                if(s==a[i]){
                    cout << count+1 << endl;
                    return 0;
                }
            }
        }
        count++;
        if(s%2==0){
            s = s/2;
        }else{
            s = 3*s+1;
        }
    }
	return 0;
}