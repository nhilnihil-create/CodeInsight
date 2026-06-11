#include<bits/stdc++.h>
#include<math.h>
using namespace std ;

int main(){
    int n;
  	cin >> n;
    vector<int> vec(n) ;

    for (int i = 0; i < n; i++)
    {
        cin >> vec.at(i) ;
      	//cout << vec.at(i) << endl;
    }

    for (int i = 0; i < n; i++)
    {
      	int y = vec.at(i);
        int x = 0 ;
        int num = 0;
        for (int j = 0; j < n; j++)
        {
            if(j >= i && x < vec.at(j)){
                x = vec.at(j);
                num = j;
            }
        }
      	//cout << x << endl ;
        for (int k = 0; k < n; k++)
        {
            if(k == num){
                vec.at(k) = y;
            }
            else if(k == i){
                vec.at(k) = x;
            }
        }    
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += pow(-1,i)*vec.at(i);
    }
    cout << ans;
    
}