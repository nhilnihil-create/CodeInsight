#include <iostream>
#include <string>
using namespace std;

int rows, column, bnykbom, m, n;
string grid [75];

int main (){
	cin>>rows>>column;
	for (int i=1; i<=rows; i++){
		cin>>grid [i];				//input grid
	}
	for (int i=1; i<=rows; i++){
		for (int j=0; j<column;j++){			//karakter dalam loop
			if (grid [i] [j]=='.'){				//cek apakah kosong
				bnykbom=0;						//yey reset
				for (int k=i-1; k<=i+1; k++){
					if (k<1){
						m=1;
                        k=1;					//biar ga out of bounds
					}else {
						m=k;
					}
					for (int l=j-1; l<=j+1; l++){
						if(l<0){
							n=0;
                            l=0;				//ga out of bounds lagi yey
						}else {
							n=l;
						}
						if (grid [m] [n]=='#'){	//cek bom apa kgk
							bnykbom++;
						}
					}
				}
				grid [i] [j]='0'+bnykbom;		//biar berubah nilainya
			}
		}
	}
	
	for (int i=1; i<=rows; i++){
		cout<<grid [i]<<endl;				//berdoa supaya outputnya bener
	}
}
