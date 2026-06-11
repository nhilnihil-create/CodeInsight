#include<iostream>
#include<string>
using namespace std;
int main()
{
  string x,y;
  cin>>x>>y;
  if(x=="A"){
    if(y=="A"){
      cout<<'=';
    }
    else if(y=="B"||y=="C"||y=="D"||y=="E"||y=="F"){
      cout<<'<';
    }
  }
  else if(x=="B"){
    if(y=="A"){
      cout<<'>';
    }
    else if(y=="B"){
      cout<<'=';
    }
    else if(y=="C"||y=="D"||y=="E"||y=="F"){
      cout<<'<';
    }
  }
  else if(x=="C"){
    if(y=="A"||y=="B"){
      cout<<'>';
    }
    else if(y=="C"){
      cout<<'=';
    }
    else if(y=="D"||y=="E"||y=="F"){
      cout<<'<';
    }
  }
  else if(x=="D"){
    if(y=="A"||y=="B"||y=="C"){
     cout<<'>';
    }
    else if(y=="D"){
      cout<<'=';
    }
    else if(y=="E"||y=="F"){
      cout<<'<';
    }
  }
  else if(x=="E"){
    if(y=="C"||y=="D"||y=="A"||y=="B"){
      cout<<'>';
    }
    else if(y=="E"){
      cout<<'=';
    }
    else if(y=="F"){
      cout<<'<';
    }
  }
  else if(x=="F"){
    if(y=="B"||y=="C"||y=="D"||y=="E"||y=="A"){
      cout<<'>';
    }
    else if(y=="F"){
      cout<<'=';
    }
  }
}