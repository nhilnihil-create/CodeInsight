#include <bits/stdc++.h>
using namespace std;


int main() {
	int Bluecard = 0;
  
	int Redcard = 0;
  
	int Max = 0;
  
	int Count = 0;
  
    string Word;
  
	cin >> Bluecard;  
  
    vector<string> Blueword(Bluecard);
  
	for (int Loop = 0; Loop < Bluecard; Loop++) {
      
    	cin >> Blueword.at(Loop);
      
    }
  
    cin >> Redcard;
  
    vector<string> Redword(Redcard);
  
    for (int Loop = 0; Loop < Redcard; Loop++) {
      
    	cin >> Redword.at(Loop);
      
        } 
  
    for (int LoopI = 0; LoopI < Bluecard; LoopI++) {
      
        Word = Blueword.at(LoopI);
      
		for (int LoopII = 0; LoopII < Bluecard; LoopII++) {
          
        	if (Word == Blueword.at(LoopII)) {
              
                Count++;
              
            }
          
        }
      
        for (int LoopII = 0; LoopII < Redcard; LoopII++) {
          
            if (Word == Redword.at(LoopII)) {
              
                Count--;
              
            }
          
        }
      
        if (Max < Count) {
          
            Max = Count;
          
        }
      
     Count = 0; 
      
    }
  
    cout << Max << endl;
  
}