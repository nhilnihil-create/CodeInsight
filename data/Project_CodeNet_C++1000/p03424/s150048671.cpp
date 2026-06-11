#include <iostream>
using namespace std;

int main(){
  int n,p=1,w=1,g=1,y=1;
  char q;
  cin >> n;
  for(int j = 0 ; j < n ; j++ ){
    cin >> q;
    switch(q){
        case 'P':
        	p=0;
        	break;
        case 'W' :
        	w=0;
        	break;
        case 'G' :
        	g=0;
        	break;
        case 'Y' :
        	y=0;
        	break;
        default :
        	break;
    }
   }
  if( 4-w-p-g-y == 3 )
    {
  cout << "Three" ;
    }else{
    cout << "Four" ;
	
    }
  return 0;
 }
