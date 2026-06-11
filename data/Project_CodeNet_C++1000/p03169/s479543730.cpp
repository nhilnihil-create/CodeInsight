#include<iostream>
#include<cmath>
#include<unordered_map>
#include<math.h>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<iomanip>
#include<string>
#include<map>
#define PI 3.14159265
#define mod 998244353  
#define mod1 1e9 + 7  
using namespace std;

double prob(vector<vector<vector<double>>> &vec, double c1 , double c2 , double c3 , double c4 , double n){
  
    double sum = 0;
    if(c4 != n){
        sum += (n / (n - c4));
    }
   
    if(c1 > 0 ){
        if(vec[c1 - 1][c2][c3] == -1)
            vec[c1 - 1][c2][c3] = prob(vec,c1 - 1,c2,c3,c4 + 1,n);
        sum += (c1 / (c1 + c2 + c3)) * vec[c1 - 1][c2][c3];
    }
    if(c2 > 0){
        if(vec[c1 + 1][c2 - 1][c3] == -1)
         vec[c1 + 1][c2 - 1][c3] = prob(vec,c1 + 1,c2 - 1,c3,c4,n);
        sum += (c2 / (c1 + c2 + c3)) * vec[c1 + 1][c2 - 1][c3];
    }
    if(c3 > 0){
    if(vec[c1][c2 + 1][c3 - 1] == -1)
        vec[c1][c2 + 1][c3 - 1] = prob(vec,c1,c2 + 1,c3 - 1,c4,n);

        sum += (c3 / (c1 + c2 + c3)) * vec[c1][c2 + 1][c3 - 1];
    }
   
    vec[c1][c2][c3] = sum;

    return sum;
 }
void func(){
    int n ;
    cin >> n ;
    double count1 = 0 , count2 = 0 , count3 = 0,c4 = 0;

   
    for(int i = 0 ; i < n ; ++i){
        int inp;
        cin >> inp;
        if(inp == 1){
            ++count1;
        }
        else if(inp == 2){
            ++count2;
        }
        else{
            ++count3;
        }
    }
   // cout << count1 << " " << count2 << " " << count3 << "\n";
    vector<vector<vector<double>>> vec(n + 1, vector<vector<double>> (n + 1, vector<double>(n + 1 , -1)));
    //cout << vec[1][2][3];
    double ans = prob(vec,count1,count2,count3 ,c4 , n);
    cout << setprecision(10) << ans << "\n";

}

int main(){
    int t = 1 , cnt = 0 ;
   // cin >> t;
    
    while(t--){
        
        func();
    }
}