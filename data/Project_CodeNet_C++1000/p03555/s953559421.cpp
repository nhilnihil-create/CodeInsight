#include<iostream>
//STL,Vector使用
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<vector<char>> vec(2,vector<char>(3));
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
        cin >> vec.at(i).at(j);
        }
    }
    //vec.at(上から何番目).at(左から何番目)
    if(vec.at(0).at(0)!=vec.at(1).at(2)){
        cout << "NO"<<endl;
        return 0;
    }
    else if(vec.at(0).at(1)!=vec.at(1).at(1)){
        cout << "NO"<<endl;
        return 0;
    }
    else if(vec.at(0).at(2)!=vec.at(1).at(0)){
        cout << "NO"<<endl;
        return 0;
    }
    
    cout << "YES"<<endl;
}