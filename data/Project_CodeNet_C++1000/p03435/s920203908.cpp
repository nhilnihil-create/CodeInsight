#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
    int i,j;
    vector<vector<int>> data(3, vector<int>(3));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int c;
            cin >> c;
            data.at(i).at(j) = c ;
        }
    }
    // c のデータを二重のvector に格納
    vector<int> A(3);
    vector<int> B(3);
    // a,bは自然数であるという仮定の下
    bool judge_1 =false;
    bool judge_2 =false;
    bool judge_3 =false;
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            for(int k=0;k<=100;k++){
                A.at(0)=i;
                A.at(1)=j;
                A.at(2)=k;
                B.at(0)= data.at(0).at(0) - A.at(0);
                B.at(1)= data.at(0).at(1) - A.at(0);
                B.at(2)= data.at(0).at(2) - A.at(0);
                if( B.at(0) != data.at(1).at(0) - A.at(1)){
                    continue;
                }
                else if( B.at(0) != data.at(2).at(0) - A.at(2)){
                    continue;
                }
                else if( B.at(1) != data.at(1).at(1) - A.at(1)){
                    continue;
                }
                else if( B.at(1) != data.at(2).at(1) - A.at(2)){
                    continue;
                }
                else if( B.at(2) != data.at(1).at(2) - A.at(1)){
                    continue;
                }
                else if( B.at(2) != data.at(2).at(2) - A.at(2)){
                    continue;
                }
                else{
                    judge_1= true;
                }
            }
            if(judge_1){
                judge_2 = true;
                break;
            }
        }
        if(judge_2){
            judge_3 = true;
            break;
        }
        
    }
    if(judge_3){ cout << "Yes" << endl;}
    else{ cout << "No" << endl;}
}