#include <bits/stdc++.h>
using namespace std;

int main() {
	int Number = 0;
	int Alice = 0;
	int Bob = 0;
	int Max = 0;
	int Cheak = 0;
	int Max_index = 0;
	cin >> Number;
	vector<int> Card(Number); 
	for (int Loop = 0; Loop < Number; Loop++) {
    	cin >> Card.at(Loop);
    }  
	for (int Loopi = 0; Loopi < Number; Loopi++) {
        Max = 0;
        Max_index = 0;
		for (int Loopii = 0; Loopii < Number; Loopii++) {
        	Cheak = Card.at(Loopii);
    		if (Cheak > Max) {
            	Max = Cheak;
        		Max_index = Loopii;
            }
        }
        	if (Loopi % 2 == 0) {
            	Alice += Max;
            }
      		else {
            	Bob += Max;
            }
         	Card.at(Max_index) = 0;
    }
    cout << Alice - Bob << endl;
}