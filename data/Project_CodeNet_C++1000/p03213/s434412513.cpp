#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

const int N = pow(10,5);

vector<bool> isp(N+1, true);

void sieve() {
  isp[0] = false;
  isp[1] = false;
  for (int i=2; pow(i,2)<=N; i++) {
    if (isp[i]) for(int j=2; i*j<=N; j++) isp[i*j] = false;
  }
}

int main() {
  int N;
  long long counter=0;
  int counter1,counter2=0;
  cin>>N;
  int a[50]={};
  sieve();
  for (long long i=2; i<=N; i++) {if (isp[i]) a[i]=1;
  else continue;}
  for(int j=2;j<50;j++){
  if(a[j]==1){
  for(int i=j;i<=N;i*=j){
  counter+=N/i;}
  a[j]=counter;
  counter=0;}
  else continue;}
  if(a[2]>=74){
  counter2++;}
  int count24=0;
  int count2=0;
  int count14=0;
  int count4=0;
  for(int j=2;j<50;j++){
  if(a[j]>=24){
  count24++;}
  if(a[j]>=14){
  count14++;}
  if(a[j]>=4){
  count4++;}
  if(a[j]>=2){
  count2++;}}
  counter2+=max(0,(count2-1)*count24)+max(0,(count14)*(count4-1))+max(0,count4*(count4-1)*(count2-2)/2);
  cout<<counter2<<endl;}