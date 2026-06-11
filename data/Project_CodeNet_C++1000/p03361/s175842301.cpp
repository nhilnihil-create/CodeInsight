#include <bits/stdc++.h>
using namespace std;
  
int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> s(h, vector<char>(w));
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      cin >> s.at(i).at(j);
    }
  }
  for(int i=1; i<h-1; i++) {
    for(int j=1; j<w-1; j++) {
      if(s.at(i).at(j) == '#') {
	    if(s.at(i).at(j-1)!='#' && s.at(i).at(j+1)!='#'
           && s.at(i-1).at(j)!='#' && s.at(i+1).at(j)!= '#') {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  for(int j=1; j<w-1; j++) {
    if(s.at(0).at(j) == '#') {
      if(s.at(0).at(j-1)!='#' && s.at(0).at(j+1)!='#'
         && s.at(1).at(j)!='#') {
        cout << "No" << endl;
        return 0;
      }
    }
    if(s.at(h-1).at(j) == '#') {
      if(s.at(h-1).at(j-1)!='#' && s.at(h-1).at(j+1)!='#'
         && s.at(h-2).at(j)!='#') {
        cout << "No" << endl;
        return 0;
      }
    } 
  }
  for(int i=1; i<h-1; i++) {
    if(s.at(i).at(0) == '#') {
      if(s.at(i-1).at(0)!='#' && s.at(i+1).at(0)!='#'
         && s.at(i).at(1)!='#') {
        cout << "No" << endl;
        return 0;
      }
    }
    if(s.at(i).at(w-1) == '#') {
      if(s.at(i-1).at(w-1)!='#' && s.at(i+1).at(w-1)!='#'
         && s.at(i).at(w-2)!='#') {
        cout << "No" << endl;
        return 0;
      }
    } 
  }
  if(s.at(0).at(0)=='#' && s.at(1).at(0)!='#' && s.at(0).at(1)!='#') {
    cout<< "No" << endl;
    return 0;
  }
  if(s.at(0).at(w-1)=='#' && s.at(1).at(w-1)!='#' && s.at(0).at(w-2)!='#') {
    cout<< "No" << endl;
    return 0;
  }
  if(s.at(h-1).at(0)=='#' && s.at(h-2).at(0)!='#' && s.at(h-1).at(1)!='#') {
    cout<< "No" << endl;
    return 0;
  }
  if(s.at(h-1).at(w-1)=='#' && s.at(h-2).at(w-1)!='#' && s.at(h-1).at(w-2)!='#') {
    cout<< "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
}