#include <time.h>

#include <stdlib.h>
#include <cstdint>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <cstdint>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <numeric>

using namespace std;



int main(){
	int64_t n;
	cin>>n;
	if(n==3){
		cout<<"2 5 63"<<endl;
	}else{
		int32_t loop=n/8;
		for(int32_t i1=0;i1<loop;i1++){
			cout<<12*i1+2<<" "<<12*i1+3<<" "<<12*i1+4<<" "<<12*i1+6<<" "<<12*i1+8<<" "<<12*i1+9<<" "<<12*i1+10<<" "<<12*i1+12<<" ";
		}
		switch(n%8){
		case 1:
			cout<<12*loop+6<<endl;
			break;
		case 2:
			cout<<12*loop+2<<" "<<12*loop+4<<endl;
			break;
		case 3:
			cout<<12*loop+2<<" "<<12*loop+4<<" "<<12*loop+6<<endl;
			break;
		case 4:
			cout<<12*loop+2<<" "<<12*loop+3<<" "<<12*loop+4<<" "<<12*loop+9<<endl;
			break;
		case 5:
			cout<<12*loop+2<<" "<<12*loop+3<<" "<<12*loop+4<<" "<<12*loop+6<<" "<<12*loop+9<<endl;
			break;
		case 6:
			cout<<12*loop+2<<" "<<12*loop+3<<" "<<12*loop+4<<" "<<12*loop+6<<" "<<12*loop+9<<" "<<12*loop+12<<endl;
			break;
		case 7:
			cout<<12*loop+2<<" "<<12*loop+3<<" "<<12*loop+4<<" "<<12*loop+8<<" "<<12*loop+9<<" "<<12*loop+10<<" "<<12*loop+12<<endl;
			break;

		}
	}

	return 0;
}

