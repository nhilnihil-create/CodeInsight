#include<stdio.h>
#include<iostream>
#include<vector>
#include <fstream>
#include<math.h>
#include <numeric>
#include<algorithm>
#include <stdlib.h>
# include <map>

using namespace std;

int main(){
    int n,m,x,y ,max_x , min_y;
    bool flag = false;
    cin >> n >> m >> x >> y;
    vector<int> vec_x(n ,0);
    vector<int> vec_y(m ,0);
    for(int i = 0;i < vec_x.size();i++ ){
        cin >> vec_x.at(i) ;
    }
    for(int i = 0;i < vec_y.size();i++ ){
        cin >> vec_y.at(i) ;
    }
    max_x = *max_element(vec_x.begin() , vec_x.end());
    min_y = *min_element(vec_y.begin() , vec_y.end());

    for(int i = x+1 ;i < y+1 ;i++){
        if ((max_x < i)&&(i <= min_y)){
            flag = true;
        }
    }
    if(flag  == true){
        cout << "No War" << endl;
    }
    else{
        cout << "War" << endl;
    }
}