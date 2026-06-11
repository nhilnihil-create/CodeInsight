#include<iostream>
using namespace std;
 
int main(){
	int N;
  	cin >> N;
  
  	int maxPrice = 0;
  	int totalPrice = 0;
  
    for(int i=0; i<N; i++){
      int price;
      cin >> price;
      if(price > maxPrice){
        maxPrice = price;
      }
      totalPrice += price;
    }
  
    int result = totalPrice - maxPrice / 2;
  
    cout << result << endl;
    return 0;
}