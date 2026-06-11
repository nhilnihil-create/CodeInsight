#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    char c;
    string S_up, S_cen, S_down, S;
    cin >> H >> W >> S_cen;

    if(H == 1 && W == 1){
        if(S_cen.at(0) == '#') S = "#";
        else S = "0";
        cout << S << endl;
    }
    else if(H == 1){
        if(S_cen.at(0) == '#') c = '#';
        else {
            c = '0';
            if(S_cen.at(1) == '#') c++;
        }
        S += c;
        for(int j = 1; j < W-1; j++){
            if(S_cen.at(j) == '#') c = '#';
            else {
                c = '0';
                if(S_cen.at(j-1) == '#') c++;
                if(S_cen.at(j+1) == '#') c++;
            }
            S += c;
        }
        if(S_cen.at(W-1) == '#') c = '#';
        else {
            c = '0';
            if(S_cen.at(W-2) == '#') c++;
        }
        S += c;
        cout << S << endl;
    }
    else if(W == 1){
        cin >> S_down;
        S = "";
        if(S_cen.at(0) == '#') c = '#';
        else{
            c = '0';
            if(S_down.at(0) == '#') c++;
        }
        S += c;
        cout << S << endl;
        for(int i = 1; i < H-1; i++){
            S_up = S_cen;
            S_cen = S_down;
            cin >> S_down;
            S = "";
            if(S_cen.at(0) == '#') c = '#';
            else{
                c = '0';
                if(S_up.at(0) == '#') c++;
                if(S_down.at(0) == '#') c++;
            }
            S += c;
            cout << S << endl;
        }
        S_up = S_cen;
        S_cen = S_down;
        S = "";
        if(S_cen.at(0) == '#') c = '#';
        else{
            if(S_up.at(0) == '#') c++;
        }
        S += c;
        cout << S << endl;
    }
    else{
    cin >> S_down;
    S = "";
    if(S_cen.at(0) == '#') c = '#';
    else{
        c = '0';
        if(S_cen.at(1) == '#') c++;
        if(S_down.at(0) == '#') c++;
        if(S_down.at(1) == '#') c++;
    }
    S += c;

    for(int j = 1; j < W-1; j++){
        if(S_cen.at(j) == '#') c = '#';
        else{
            c = '0';
            if(S_cen.at(j-1) == '#') c++;
            if(S_cen.at(j+1) == '#') c++;
            if(S_down.at(j-1) == '#') c++;
            if(S_down.at(j) == '#') c++;
            if(S_down.at(j+1) == '#') c++;
        }
        S += c;
    }

    if(S_cen.at(W-1) == '#') c = '#';
    else{
        c = '0';
        if(S_cen.at(W-2) == '#') c++;
        if(S_down.at(W-2) == '#') c++;
        if(S_down.at(W-1) == '#') c++;
    }
    S += c;

    cout << S << endl;

    for(int i = 1; i < H-1; i++){
        S_up = S_cen;
        S_cen = S_down;
        cin >> S_down;
        S = "";
        if(S_cen.at(0) == '#') c = '#';
        else{
            c = '0';
            if(S_up.at(0) == '#') c++;
            if(S_up.at(1) == '#') c++;
            if(S_cen.at(1) == '#') c++;
            if(S_down.at(0) == '#') c++;
            if(S_down.at(1) == '#') c++;
        }
        S += c;

        for(int j = 1; j < W-1; j++){
            if(S_cen.at(j) == '#') c = '#';
            else{
                c = '0';
                if(S_up.at(j-1) == '#') c++;
                if(S_up.at(j) == '#') c++;
                if(S_up.at(j+1) == '#') c++;
                if(S_cen.at(j-1) == '#') c++;
                if(S_cen.at(j+1) == '#') c++;
                if(S_down.at(j-1) == '#') c++;
                if(S_down.at(j) == '#') c++;
                if(S_down.at(j+1) == '#') c++;
            }
            S += c;
        }

        if(S_cen.at(W-1) == '#') c = '#';
        else{
            c = '0';
            if(S_up.at(W-2) == '#') c++;
            if(S_up.at(W-1) == '#') c++;
            if(S_cen.at(W-2) == '#') c++;
            if(S_down.at(W-2) == '#') c++;
            if(S_down.at(W-1) == '#') c++;
        }
        S += c;

        cout << S << endl;        
    }

    S_up = S_cen;
    S_cen = S_down;
    S = "";
    if(S_cen.at(0) == '#') c = '#';
    else{
        c = '0';
        if(S_cen.at(1) == '#') c++;
        if(S_up.at(0) == '#') c++;
        if(S_up.at(1) == '#') c++;
    }
    S += c;

    for(int j = 1; j < W-1; j++){
        if(S_cen.at(j) == '#') c = '#';
        else{
            c = '0';
            if(S_cen.at(j-1) == '#') c++;
            if(S_cen.at(j+1) == '#') c++;
            if(S_up.at(j-1) == '#') c++;
            if(S_up.at(j) == '#') c++;
            if(S_up.at(j+1) == '#') c++;
        }
        S += c;
    }

    if(S_cen.at(W-1) == '#') c = '#';
    else{
        c = '0';
        if(S_cen.at(W-2) == '#') c++;
        if(S_up.at(W-2) == '#') c++;
        if(S_up.at(W-1) == '#') c++;
    }
    S += c;

    cout << S << endl;
    }
}
