#include<iostream>
#include<string>
#include<array>

int main(){
  	std::string s,t;
  	std::array<int, 26> sm, tm;
  	int sc=0, tc=0;
  	sm.fill(-1);
  	tm.fill(-1);
  	std::cin >> s >> t;
  	bool ans=true;
  	for(int i=0;i<s.size();i++){
      	int se,te;
      	if(sm.at(s.at(i)-'a')==-1){
          	se = sc;
          	sm.at(s.at(i)-'a') = sc;
          	sc++;
        }else{
          	se = sm.at(s.at(i)-'a');
        }
      	if(tm.at(t.at(i)-'a')==-1){
          	te = tc;
          	tm.at(t.at(i)-'a') = tc;
          	tc++;
        }else{
          	te = tm.at(t.at(i)-'a');
        }
      	if(se!=te){
          	ans=false;
          	break;
        }
    }
  	if(ans){
      	std::cout << "Yes\n";
    }else{
      	std::cout << "No\n";
    }
  	return 0;
}