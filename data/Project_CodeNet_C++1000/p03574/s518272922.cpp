#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string Sa,Sb,Sc,dod=".";
	int TATE, YOKO ;
    cin >> TATE >> YOKO >>Sb ;
    Sa = dod + dod + dod;
    Sb = dod+Sb+dod;
  

  
    for (int tate = 0; tate  < TATE ; tate++){

      if (tate != TATE){   
        cin >> Sc ;
      if (tate == (TATE-1)) {
        Sc = dod + dod + dod ;
      }
      }
  
       for (int LOOK = 0; LOOK < YOKO ; LOOK++){
         
         int sum = 0;
         
  			if ( tate == 0){
    			Sa = Sa + dod;
    				}
            
   			if (LOOK==0){
                      Sc = dod+Sc;
   					 }
            if (tate == (TATE-1)){
                     Sc = Sc + dod  ;
            }
         
   			if (LOOK==(YOKO-1)){
                      Sc = Sc+dod;
   					 }
          
    
    		char A,B,C,D,E,F,G,H,I;
   			 A = Sa.at(LOOK);
   			 B = Sa.at(LOOK+1);
   			 C = Sa.at(LOOK+2);
   			 D = Sb.at(LOOK);
   			 E = Sb.at(LOOK+1);
   			 F = Sb.at(LOOK+2);
   			 G = Sc.at(LOOK);
   			 H = Sc.at(LOOK+1);
   			 I = Sc.at(LOOK+2);
  
  
    		 if (E == '#'){
    			cout << '#';
   			 }else{
   			   if (A == '#'){
  			      sum++;
   			   }if (B == '#'){
  			      sum++;
   			   }if (C == '#'){
			      sum++;
   			   }if (D == '#'){
  			      sum++;
   			   }if (F == '#'){
   			      sum++;
  			   }if (G == '#'){
  			      sum++;
   			   }if (H == '#'){
 			      sum++;
 		       }if (I == '#'){
   			      sum++;
  		       }
                        
   	          cout << sum;
             }

    } 
           
     Sa = Sb;
     Sb = Sc;

     cout << endl;
   }
}
